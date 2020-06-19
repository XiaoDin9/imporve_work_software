#ifndef _ENVIRONMENT_HEAD_H_
#define _ENVIRONMENT_HEAD_H_

// 使用环境变量设置打印, 例如：export DEBUG=1，就可以打印调试信息

#define MODULE_NAME_PRINT_ALL_ENVIRONMENT     "PRINT_ALL_ENVIRONMENT"     // 0: 打印所有的环境变量，1：设置不打印
#define MODULE_NAME_DEBUG     "DEBUG"              // 1：打印调试信息
#define MODULE_NAME_PROFILE   "PROFILE"            // 1: 打印耗时信息
#define MODULE_NAME_PRINT_LEVEL   "PRINT_LEVE"     // 1: 打印各个打印的水平
#define MODULE_NAME_DUMP_PATH     "DUMP_PATH"      // 1: dump 保存数据的路径

class Environment {
public:
  int get_all_environment_info();
  int get_debug_info();
  int get_profile_info();
  int get_print_level_info();
  std::string get_dump_path_info();
  
private:
  int get_env_val(std::string envInputVal);
  std::string get_env_str(std::string envInputVal);
};

#endif
