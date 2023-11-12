#!/bin/bash

set -e

ENV_DIR="playground"

function build() {
  local language=$1
  local basedir=$2

  local filename=`ls -1 ${basedir}/*.${language} | head -n 1`

  local destdir="${ENV_DIR}/problem"
  mkdir -p "${destdir}"

  case ${language} in
	cpp)
	  cp "stdc++.h" "${ENV_DIR}"
	  cp "${filename}" "${destdir}/solution.cpp"
	  g++ "${destdir}/solution.cpp" -o ${ENV_DIR}/solution
	  ;;

	py)
	  cp "${filename}" ${ENV_DIR}/solution.py
	  ;;

	*)
	  echo "${language} is not supported"
	  exit 1
	  ;;
  esac
}

function test() {
  local language=$1
  local basedir=$2

  cp "${basedir}"/*.in "${ENV_DIR}"
  cp "${basedir}"/*.ou "${ENV_DIR}"

  case ${language} in
  	cpp)
	  local runcmd=(./solution)
  	  ;;

  	py)
  	  local runcmd=(python3 solution.py)
  	  ;;

	*)
	  echo "${language} is not supported"
	  exit 1
	  ;;
  esac

  pushd ${ENV_DIR}

  if ls *.in; then
  	for in in *.in; do
  	  name=$(basename -s .in "$in")
  	  printf "\nTEST: %s\n" "${in}"
	  "${runcmd[@]}" < "$in" | tee output
	  if [ -f "${name}.ou" ]; then
		diff output "${name}.ou"
	  fi
	done
  else
  	echo "Help: To insert EOF do [Unix] Ctrl + D"
	"${runcmd[@]}" < /dev/stdin | tee output
  fi

  popd
}

judge="$1"
problem="$2"
language="$3"

basedir="${judge}/${problem}"
mkdir -p "${ENV_DIR}"

build "${language}" "${basedir}"
test "${language}" "${basedir}"
