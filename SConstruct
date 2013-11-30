# Normal build environment
env = Environment(CCFLAGS=['-std=c++11', '-O3'])

# Testing environment
test_env = Environment(
    CCFLAGS=['-std=c++11', '-g', '-fprofile-arcs', '-ftest-coverage'])
test_env.Append(LIBS=['cppunit', 'gcov'])

# Test suite
test_program = test_env.Program('test_suite', Glob('src/test_*.cpp'))
test_alias = test_env.Alias('test', [test_program], test_program[0].abspath)
AlwaysBuild(test_alias)

# Coverage report
coverage_lcov = test_env.Command('coverage.info', [], 'lcov --no-external -c -d . -o $TARGET')
Depends(coverage_lcov, test_alias)
coverage_html = test_env.Command('coverage/', 'coverage.info', 'genhtml $SOURCE -o $TARGET')
test_env.Clean(coverage_html, 'coverage/')
Depends(coverage_html, coverage_lcov)
test_env.Alias('coverage', 'coverage/')

# Documentation
doc_doxygen = env.Command(
    target='doc/doxyxml/xml/index.xml',
    source=[Glob('src/*.hpp'), 'doc/doxygen.cfg'],
    action='doxygen doc/doxygen.cfg')
doc_sphinx = env.Command(
    target='doc/_build/index.html',
    source=[Glob('doc/**.rst'), 'doc/doxyxml/xml/index.xml'],
    action='sphinx-build2 -b html doc doc/_build')
Depends(doc_sphinx, doc_doxygen)
env.Alias('doc', doc_sphinx)

# Iteration benchmark
bench_main = env.Program('main', 'src/main.cpp')
Default('main')
