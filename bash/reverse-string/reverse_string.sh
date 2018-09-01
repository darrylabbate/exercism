#!/usr/bin/env bash

# `rev` is not mandated by POSIX, but from what I understand, it's fairly ubiquitous

echo $@ | rev
