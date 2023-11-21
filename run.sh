echo "=========GO============"
cd $TDD_PROJECT_ROOT/go
go test . -v
go fmt ./...
echo "======================="

echo "=========JS============"
node $TDD_PROJECT_ROOT/js/test_money.js
echo "======================="

echo "=========PY============"
python3 $TDD_PROJECT_ROOT/py/test_money.py
echo "======================="

echo "=========C++============"
cd $TDD_PROJECT_ROOT/cpp
make clean
make
./test_money
echo "======================="