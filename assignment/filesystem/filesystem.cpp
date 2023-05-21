#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <unordered_map>
#include <fstream>
#include <filesystem>
#include <algorithm>

namespace fs = std::filesystem;

class ProjectFiles {
public:
    std::set<std::string> projects;
};

struct SetHash {
    size_t operator()(const std::set<std::string>& s) const {
        std::hash<std::string> hash_fn;
        size_t seed = 0;
        for (const auto& val : s) {
            seed ^= hash_fn(val) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
        }
        return seed;
    }
};

struct SetEqual {
    bool operator()(const std::set<std::string>& lhs, const std::set<std::string>& rhs) const {
        return lhs == rhs;
    }
};

std::unordered_map<std::set<std::string>, std::vector<std::string>, SetHash, SetEqual> grouped_data;

void scanDirectory(const std::string& directoryPath, const std::string& basePath, std::unordered_map<std::string, ProjectFiles>& projectFileMap, const std::string& currentProject = "") {
    for (const auto& entry : fs::directory_iterator(directoryPath)) {
        if (entry.is_directory()) {
            std::string relativePath = entry.path().string().substr(basePath.length() + 1);
            std::string newProject = currentProject + "/" + relativePath;
            scanDirectory(entry.path().string(), basePath, projectFileMap, newProject);
        }
        else if (entry.is_regular_file()) {
            std::string filename = entry.path().filename().string();
            std::string project = (currentProject == "") ? "/" : currentProject;
            std::string fileExtension = entry.path().extension().string();
            if (fileExtension == ".c" || fileExtension == ".h" || fileExtension == ".cpp" || fileExtension == ".rc") {
                projectFileMap[filename].projects.insert(project);
            }
        }
    }
}

void printProjectsAndFiles(const std::unordered_map<std::string, ProjectFiles>& projectFileMap, std::ofstream& output) {
    grouped_data.clear(); // Clear the map before each run

    std::vector<std::pair<std::string, std::set<std::string>>> a;
    for (const auto& entry : projectFileMap) {
        a.emplace_back(entry.first, entry.second.projects);
    }

    // Create a dictionary to store the grouped entries
    for (const auto& entry : a) {
        const std::set<std::string>& key = entry.second;
        const std::string& value = entry.first;
        grouped_data[key].push_back(value);
    }

    // Print the grouped data
    for (const auto& entry : grouped_data) {
        const std::set<std::string>& key = entry.first;
        const std::vector<std::string>& values = entry.second;
        for (const std::string& project : key) {
            std::cout << project << std::endl;
            output << project << std::endl;
        }
        for (const std::string& value : values) {
            std::cout << "  " << value << std::endl;
            output << "\t" << value << std::endl;
        }
    }
}

std::set<std::string> getCommonFiles(const std::unordered_map<std::string, ProjectFiles>& projectFileMap) {
    std::set<std::string> common_files = projectFileMap.begin()->second.projects;
    for (const auto& entry : projectFileMap) {
        const ProjectFiles& projectFiles = entry.second;
        std::set<std::string> current_files = projectFiles.projects;
        std::set<std::string> temp;
        std::set_intersection(common_files.begin(), common_files.end(), current_files.begin(), current_files.end(), std::inserter(temp, temp.begin()));
        common_files = temp;
    }
    return common_files;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "Usage: program_name <base_folder_path>" << std::endl;
        return 1;
    }

    std::string baseFolderPath = argv[1];
    std::unordered_map<std::string, ProjectFiles> ProjectFileMap;

    scanDirectory(baseFolderPath, baseFolderPath, ProjectFileMap);

    std::string outputFilePath = "output.txt";
    std::ofstream outputFile(outputFilePath);
    if (!outputFile) {
        std::cout << "Unable to open output file." << std::endl;
        return 1;
    }

    printProjectsAndFiles(ProjectFileMap, outputFile);

    outputFile.close();
    std::cout << "Output written to " << outputFilePath << std::endl;

    return 0;
}