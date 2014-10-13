GXX=g++
GTEST_ROOT= /opt/gtest

bin/order_statistics_test: src/order_statistics_test.cpp src/order_statistics.h
	$(GXX) -std=c++11 -Wall -o bin/order_statistics_test src/order_statistics_test.cpp -I$(GTEST_ROOT)/include -L$(GTEST_ROOT)/lib -lgtest -lpthread
	bin/order_statistics_test

bin/read_last_lines_test: src/read_last_lines_test.cpp src/read_last_lines.h
	$(GXX) -std=c++11 -Wall -o bin/read_last_lines_test src/read_last_lines_test.cpp -I$(GTEST_ROOT)/include -L$(GTEST_ROOT)/lib -lgtest -lpthread
	bin/read_last_lines_test

bin/rectangle_intersection_test: src/rectangle_intersection_test.cpp src/rectangle_intersection.h
	$(GXX) -std=c++11 -Wall -o bin/rectangle_intersection_test src/rectangle_intersection_test.cpp -I$(GTEST_ROOT)/include -L$(GTEST_ROOT)/lib -lgtest -lpthread
	bin/rectangle_intersection_test

bin/single_linked_list_test: src/single_linked_list_test.cpp src/single_linked_list.h
	$(GXX) -std=c++11 -Wall -o bin/single_linked_list_test src/single_linked_list_test.cpp -I$(GTEST_ROOT)/include -L$(GTEST_ROOT)/lib -lgtest -lpthread
	bin/single_linked_list_test
