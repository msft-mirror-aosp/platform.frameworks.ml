#!/bin/bash
#
set -e
cd $(dirname $(realpath $0))
../../parse_systrace.py hdrnet.html > hdrnet.tmp
../../parse_systrace.py cpu.html > cpu.tmp
../../parse_systrace.py unittest.html > unittest.tmp
../../parse_systrace.py --per-execution hdrnet.html > hdrnet-bm.tmp

echo hdrnet
diff hdrnet.txt hdrnet.tmp
echo cpu
diff cpu.txt cpu.tmp
echo unittest
diff unittest.txt unittest.tmp
echo benchmark
diff hdrnet-bm.txt hdrnet-bm.tmp

echo Success
