#!/usr/bin/expect
spawn scp -r -P 4242 source.c level00@localhost:/tmp
set pass "level00"
expect {
    password: {send "$pass\r"; exp_continue}
}
