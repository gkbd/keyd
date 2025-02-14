#!/bin/sh

# TODO: make this more robust

cleanup() {
	sudo pkill keyd
	sleep .5s
	sudo systemctl restart keyd

	trap - EXIT
	exit
}

trap cleanup INT EXIT

cd "$(dirname $0)"

sudo cp test.conf /etc/keyd
sudo pkill keyd
sleep .5s
sudo ../bin/keyd -d || exit
sleep .5s

if [ $# -ne 0 ]; then
	test_files="$(echo "$@"|sed -e 's/ /.t /g').t"
	sudo ./runner.py -v $test_files
	exit
fi

sudo ./runner.py -ev *.t || exit
sudo ./runner.py -ev $(seq 100|sed -e 's@.*@overload-timeout.t@')
