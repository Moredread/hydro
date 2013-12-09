import re
import subprocess


def get_lcov_version():
    """Determines version of lcov"""
    p = subprocess.Popen(['lcov', '--version'], stdout=subprocess.PIPE)
    out, err = p.communicate()
    m = re.search('LCOV version (\d+)\.(\d+)', str(out))
    if m:
        return int(m.group(1)), int(m.group(2))

def lcov_supports_no_external():
    """Determines whether lcov supports the --no-external flag"""
    version = get_lcov_version()
    return (version[0] == 1 and version[1] >= 10)

if lcov_supports_no_external():
    lcov_cmd = 'lcov --no-external -c'
else:
    lcov_cmd = 'lcov -c'


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
coverage_lcov = test_env.Command('coverage.info', [], lcov_cmd + ' -d . -o $TARGET')
Depends(coverage_lcov, test_alias)
coverage_html = test_env.Command('coverage/', 'coverage.info', 'genhtml $SOURCE -o $TARGET')
test_env.Clean(coverage_html, 'coverage/')
Depends(coverage_html, coverage_lcov)
test_env.Alias('coverage', 'coverage/')

# Iteration benchmark
bench_main = env.Program('main', 'src/main.cpp')
Default('main')
