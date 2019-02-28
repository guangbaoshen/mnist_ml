#ifndef __DATA_HANDLER_H
#define __DATA_HANDLER_H

#include "fstream"
#include "stdint.h"
#include "data.h"
#include <vector>
#include <string>
#include <map>
#include <unordered_set>

class data_handler
{
  std::vector<data *> *data_array; // all of the data
  std::vector<data *> *training_data;
  std::vector<data *> *test_data;
  std::vector<data *> *validation_data;
  int class_counts;
  int feature_vector_size;
  std::map<uint8_t, int> class_map;

  public:
  const double TRAIN_SET_PERCENT = 0.75;
  const double TEST_SET_PERCENT = 0.20;
  const double VALID_SET_PERCENT = 0.05;

  data_handler();
  ~data_handler();

  void read_input_data(std::string path);
  void read_label_data(std::string path);
  void split_data();
  void count_classes();
  
  int get_class_counts();
  int get_data_array_size();
  int get_training_data_size();
  int get_test_data_size();
  int get_validation_size();

  uint32_t fix_endianness(const unsigned char* bytes);

  std::vector<data *> * get_training_data();
  std::vector<data *> * get_test_data();
  std::vector<data *> * get_validation_data();
  std::map<uint8_t, int> get_class_map();

};

#endif
