/**
 * @class CommandLineReader reads the command line string provided by the user, parses it and extracts the relevant parameters.
 *
 */

#ifndef COMMAND_LINE_READER_H_
#define COMMAND_LINE_READER_H_

#include <iostream>
#include <string>

class CommandLineReader {
public:
    // Singleton: only one command line
    static CommandLineReader& getInstance();

    // Getters and setters
    std::string getRefFilePath() const;
    std::string getFloFilePath() const;
    std::string getMaskFilePath() const;
    std::string getOutDir() const;
    std::string getInitCPPPath() const;
    unsigned int getLevelToPerform() const;
    bool getUseConstraint() const;
    bool justHelp() const;
    void processCmdLineOptions(int argc, char **argv);
    void printUsage(std::ostream &stream) const;
    void writeCommandLine(int argc, char **argv);

private:
    CommandLineReader();
    CommandLineReader(CommandLineReader const&) = delete;
    void operator= (CommandLineReader const&) = delete;

    static const std::string kUsageMsg;
    std::string m_refPath;
    std::string m_floPath;
    std::string m_maskPath;
    std::string m_outDir;
    std::string m_initCPPPath;
    unsigned int m_levelToPerform;
    bool m_useConstraint;
    bool m_usage;
};


#endif // COMMAND_LINE_READER_H_