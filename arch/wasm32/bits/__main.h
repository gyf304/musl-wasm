#define __MAIN_0_ARGS()                            _main0()
#define __MAIN_1_ARGS(argc)                        _main1(argc)
#define __MAIN_2_ARGS(argc, argv)                  _main2(argc, argv)
#define __MAIN_3_ARGS(argc, argv, envp)            _main3(argc, argv, envp)
#define __GET_4TH_ARG(arg1, arg2, arg3, arg4, ...) arg4

#define __MAIN_MACRO_CHOOSER(...) \
	__GET_4TH_ARG(__VA_ARGS__, __MAIN_3_ARGS, __MAIN_2_ARGS, __MAIN_1_ARGS, __MAIN_0_ARGS, )

#define main(...) __MAIN_MACRO_CHOOSER(__VA_ARGS__)(__VA_ARGS__)
