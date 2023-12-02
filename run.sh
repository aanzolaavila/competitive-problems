#!/bin/bash

ENV_DIR="playground"

function build() {
  local language=$1
  local basedir=$2

  local filename=`ls -1 ${basedir}/*.${language} | head -n 1`

  local destdir="${ENV_DIR}/problem"
  mkdir -p "${destdir}"

  set -e
  case ${language} in
	cpp)
	  cp "${filename}" "${destdir}/solution.cpp"
	  g++ -std=c++11 -w "${destdir}/solution.cpp" -o ${ENV_DIR}/solution
	  ;;

	py)
	  cp "${filename}" ${ENV_DIR}/solution.py
	  ;;

	rs)
	  cp "${filename}" "${destdir}/solution.rs"
	  rustc "${destdir}/solution.rs" -o ${ENV_DIR}/solution
	  ;;

	*)
	  echo "${language} is not supported"
	  exit 1
	  ;;
  esac
  set +e
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

  	rs)
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

  if ls *.in >/dev/null; then
  	for in in *.in; do
  	  name=$(basename -s .in "$in")
  	  printf "\nTEST: %s\n" "${in}"
  	  set -e
	  "${runcmd[@]}" < "$in" | tee output
	  if [ -f "${name}.ou" ]; then
		diff "${name}.ou" output
	  fi
  	  set +e
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
rm -rf "${ENV_DIR}"
mkdir -p "${ENV_DIR}"

build "${language}" "${basedir}"
test "${language}" "${basedir}"
