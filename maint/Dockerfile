FROM ubuntu:18.04 AS builder

RUN --mount=type=bind,target=/src <<EOF
#!/bin/bash

set -euxo pipefail

env DEBIAN_FRONTEND=noninteractive apt-get update
env DEBIAN_FRONTEND=noninteractive apt-get install -y gcc libc6-dev tar

_ARCHNAME=$(if [ $(uname -m) = x86_64 ]; then echo amd64; else echo arm64; fi)
mkdir idle-forever-linux-$_ARCHNAME
gcc -Wall -Wextra -o idle-forever-linux-$_ARCHNAME/idle-forever /src/idle-forever.c
tar --owner=0 --group=0 --numeric-owner -czf \
  idle-forever-linux-$_ARCHNAME.tar.gz idle-forever-linux-$_ARCHNAME
EOF

FROM scratch
COPY --from=builder /idle-forever-linux-*.tar.gz /
