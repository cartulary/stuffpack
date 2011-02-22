#!/usr/bin/env sh
for remote in $(<.remotes cat)
do
	hg "$@" "$remote";
done
