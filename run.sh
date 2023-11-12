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
  local infile=$3
  local outfile=$4

  if [ -n "${infile}" ]; then
	cp "${basedir}/${infile}" "${ENV_DIR}/infile"
  fi

  if [ -n "${outfile}" ]; then
	cp "${basedir}/${outfile}" "${ENV_DIR}/outfile"
  fi

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
  if [ -f "infile" ]; then
	"${runcmd[@]}" < infile | tee output
  else
  	echo "Help: To insert EOF do [Unix] Ctrl + D"
	"${runcmd[@]}" < /dev/stdin | tee output
  fi

  if [ -f "outfile" ]; then
  	echo ">>>>>>>> DIFFERENCE: <<<<<<<<"
	diff "${outfile}" output
  fi
  popd
}

judge="$1"
problem="$2"
language="$3"
infile="$4"
outfile="$5"

basedir="${judge}/${problem}"
mkdir -p "${ENV_DIR}"

build "${language}" "${basedir}"
test "${language}" "${basedir}" "${infile}" "${outfile}"
