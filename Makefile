GXX=g++
GTEST_ROOT= /opt/gtest

bin/order_statistics_test: src/order_statistics_test.cpp src/order_statistics.h
	$(GXX) -Wall -o bin/order_statistics_test src/order_statistics_test.cpp -I$(GTEST_ROOT)/include -L$(GTEST_ROOT)/lib -lgtest -lpthread
