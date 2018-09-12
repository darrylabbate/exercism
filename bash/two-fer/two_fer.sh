#!/usr/bin/env bash

main ()
{
  local NAME=$1

  if [[ ${NAME} ]]; then
    YOU=${NAME}
  else
    YOU="you"
  fi

  printf "One for %s, one for me.\\n" "$YOU"
}

main "$1"
