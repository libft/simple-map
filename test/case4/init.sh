#!/bin/sh

set -e

if [ -d leak_test ]; then
  exit 0
fi

TMPFILE=$(mktemp)
trap 'rm -rf -- "$TMPFILE"' EXIT
DOWNLOAD_URL="https://github.com/libft/leak_test/releases/download/v0.0.3/sources.zip"
curl -L -o "$TMPFILE" "$DOWNLOAD_URL"
unzip -o "$TMPFILE" -d "leak_test"
