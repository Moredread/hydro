#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/ui/text/TestRunner.h>


int main( int argc, char **argv)
{
    // Set up runner and factory registry
    CppUnit::TextUi::TestRunner runner;
    CppUnit::TestFactoryRegistry &registry = CppUnit::TestFactoryRegistry::getRegistry();
    runner.addTest(registry.makeTest());
    // Run the test suite
    bool success = runner.run("", false);
    // Return suitable exit code
    return success ? 0 : 1;
}
