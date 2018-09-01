#!/usr/bin/env bash

main ()
{
  local NAME=$1

  if [[ ${NAME} ]]; then
    YOU=${NAME}
  else
    YOU="you"
  fi

  printf "One for ${YOU}, one for me.\\n"
}

main "$1"
