#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/ui/text/TestRunner.h>

#include <string>


int main(int argc, char **argv)
{
    // Set up runner and factory registry
    CppUnit::TextUi::TestRunner runner;
    CppUnit::TestFactoryRegistry &registry = CppUnit::TestFactoryRegistry::getRegistry();
    runner.addTest(registry.makeTest());
    // Run the test suite
    std::string test_name = "";
    if (argc == 2) {
        test_name = argv[1];
    }
    bool success = runner.run(test_name, false);
    // Return suitable exit code
    return success ? 0 : 1;
}
