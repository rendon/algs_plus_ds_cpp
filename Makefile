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

bin/bst_test: src/bst_test.cpp src/bst.h
	$(GXX) -std=c++11 -Wall -o bin/bst_test src/bst_test.cpp -I$(GTEST_ROOT)/include -L$(GTEST_ROOT)/lib -lgtest -lpthread
	bin/bst_test

bin/queue_test: src/queue_test.cpp src/queue.h
	$(GXX) -std=c++11 -Wall -o bin/queue_test src/queue_test.cpp -I$(GTEST_ROOT)/include -L$(GTEST_ROOT)/lib -lgtest -lpthread
	bin/queue_test

bin/stack_test: src/stack_test.cpp src/stack.h
	$(GXX) -std=c++11 -Wall -o bin/stack_test src/stack_test.cpp -I$(GTEST_ROOT)/include -L$(GTEST_ROOT)/lib -lgtest -lpthread
	bin/stack_test

bin/trie_test: src/trie_test.cpp src/trie.h
	$(GXX) -std=c++11 -Wall -o bin/trie_test src/trie_test.cpp -I$(GTEST_ROOT)/include -L$(GTEST_ROOT)/lib -lgtest -lpthread
	bin/trie_test

bin/word_break_test: src/word_break_test.cpp src/word_break.h
	$(GXX) -std=c++11 -Wall -o bin/word_break_test src/word_break_test.cpp -I$(GTEST_ROOT)/include -L$(GTEST_ROOT)/lib -lgtest -lpthread
	bin/word_break_test

bin/peak_test: src/peak_test.cpp src/peak.h
	$(GXX) -std=c++11 -Wall -o bin/peak_test src/peak_test.cpp -I$(GTEST_ROOT)/include -L$(GTEST_ROOT)/lib -lgtest -lpthread
	bin/peak_test
