#include "../../include/environment.h"

#define LOG_LEVEL_FATAL (0)
#define LOG_LEVEL_ERROR (1)
#define LOG_LEVEL_WARNING (2)
#define LOG_LEVEL_INFO   (3)
#define LOG_LEVEL_DEBUG  (4)
#define LOG_LEVEL_VERSONRE (5)

/**
* 得到环境变量的值
*/
int Environment::get_env_val(std::string envInputVal) {
 
   char *debugParm = getenv(envInputVal.c_str());       
   int val = 0;     // 保持环境变量的值
   if(debugParm) {
      val = atoi(debugParm);
   }
  
   return val;
}

/**
* 得到环境变量
*/
std::string get_env_str(std::string envInputVal) {
  
   std::string res = "";
   const char *envVal = getenv(envInputVal.c_str());
   if(envVal) {
      res = envVal;
   }
  
   return res;
}

/// 是否开启debug
int Environment::get_debug_info() {
   return get_env_val(MODULE_NAME_DEBUG);
}

/// 是否开启打印profile
int Environment::get_profile_info() {
   return get_env_val(MODULE_NAME_PROFILE);
}

/// 得到所有的打印级别
int Environment::get_print_level_info() {
   
   int ret = get_env_val(MODULE_NAME_PRINT_LEVEL);
   if(ret == 0) 
      return LOG_LEVEL_VERSONRE;
   
   return ret;
}

/// 开启所有环境变量
int get_all_environment_info() {
   
   if(get_env_val(MODULE_NAME_PRINT_ALL_ENVIRONMENT))
   {
        get_debug_info();
        get_profile_info();
        get_dump_path_info();
   }
   return 1;
}

std::string Environment::get_dump_path_info() {
   return get_env_str(MODULE_NAME_DUMP_PATH);
}


#define LOG_ERROR(fmt, ...)                                                   \
  if(Environment::get_print_level_info() >= LOG_LEVEL_ERROR) {
     printf(RED "%s[%d]: " fmt "\n" END, __func__, __LINE__, ##__VA_ARGS__);  \
  }                                                                           \
       
       
       
       
       
       
       
       
       
       
       
       
