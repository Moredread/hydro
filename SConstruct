# Setup environment
env = Environment()
env.Append(LIBS=['cppunit'])

# Compile test suite
test_program = env.Program('test_suite', Glob('src/test_*.cpp'))
test_alias = env.Alias('test', [test_program], test_program[0].abspath)
AlwaysBuild(test_alias)
