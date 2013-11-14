# Setup environment
env = Environment(CCFLAGS=['-std=c++11'])
env.Append(LIBS=['cppunit'])

# Compile test suite
test_program = env.Program('test_suite', Glob('src/test_*.cpp'))
test_alias = env.Alias('test', [test_program], test_program[0].abspath)
AlwaysBuild(test_alias)

# Iteration benchmark
bench_main = env.Program('main', 'src/main.cpp')
