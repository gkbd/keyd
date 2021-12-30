.PHONY: all clean install install-usb-gadget install-vkbd-usb-gadget uninstall uninstall-usb-gadget uninstall-vkbd-usb-gadget debug man
DESTDIR=
PREFIX=/usr

LOCK_FILE="/var/lock/keyd.lock"
LOG_FILE="/var/log/keyd.log"
CONFIG_DIR="/etc/keyd"

VERSION=2.1.0-beta
GIT_HASH=$(shell git describe --no-match --always --abbrev=40 --dirty)

CFLAGS+=-DVERSION=\"$(VERSION)\" \
	-DGIT_COMMIT_HASH=\"$(GIT_HASH)\" \
	-DCONFIG_DIR=\"$(CONFIG_DIR)\" \
	-DLOG_FILE=\"$(LOG_FILE)\" \
	-DLOCK_FILE=\"$(LOCK_FILE)\"\
	-I/usr/local/include\
	-L/usr/local/lib\

all: vkbd-uinput
vkbd-%:
	mkdir -p bin
	$(CC) $(CFLAGS) -O3 src/*.c src/vkbd/$(@:vkbd-%=%).c -o bin/keyd -ludev
debug:
	CFLAGS='-pedantic -Wall -Wextra -g' $(MAKE)
man:
	pandoc -s -t man man.md | gzip > keyd.1.gz
clean:
	-rm -rf bin
install:
	mkdir -p $(DESTDIR)/etc/keyd
	mkdir -p $(DESTDIR)$(PREFIX)/lib/systemd/system
	mkdir -p $(DESTDIR)$(PREFIX)/bin
	mkdir -p $(DESTDIR)$(PREFIX)/share/man/man1

	install -m644 keyd.service $(DESTDIR)$(PREFIX)/lib/systemd/system
	install -m755 bin/keyd $(DESTDIR)$(PREFIX)/bin
	install -m644 keyd.1.gz $(DESTDIR)$(PREFIX)/share/man/man1
install-vkbd-usb-gadget:
	install -m644 keyd-usb-gadget.service $(DESTDIR)$(PREFIX)/lib/systemd/system
	install -m755 src/vkbd/keyd-usb-gadget.sh $(DESTDIR)$(PREFIX)/bin
install-usb-gadget: install install-vkbd-usb-gadget
uninstall:
	rm -f $(DESTDIR)$(PREFIX)/lib/systemd/system/keyd.service\
		bin/keyd $(DESTDIR)$(PREFIX)/bin/keyd\
		$(DESTDIR)$(PREFIX)/share/man/man1/keyd.1.gz
uninstall-vkbd-usb-gadget:
	rm -f $(DESTDIR)$(PREFIX)/lib/systemd/system/keyd-usb-gadget.service\
		$(DESTDIR)$(PREFIX)/bin/keyd-usb-gadget.sh
uninstall-usb-gadget: uninstall uninstall-vkbd-usb-gadget
test: all
	@cd t; \
	for f in *.sh; do \
		./$$f; \
	done
