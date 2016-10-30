// https://code.google.com/codejam/contest/635101/dashboard

#include <iostream>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<string> split(string input, char delimiter);
int graphAdd(unordered_map<string, vector<string> > &graph, vector<string> split);
int solve(vector<string> &existingDirs, vector<string> &newDirs);

int main() {
	int T = 0;
	cin >> T;

	for ( int i = 0; i < T; i++ ) {
		int N = 0;
		int M = 0;
		cin >> N;
		cin >> M;

		vector<string> existingDirs;
		vector<string> newDirs;

		for ( int j = 0; j < N; j++ ) {
			string existingDir = "";
			cin >> existingDir;
			existingDirs.push_back(existingDir);
		}

		for ( int j = 0; j < M; j++ ) {
			string newDir = "";
			cin >> newDir;
			newDirs.push_back(newDir);
		}

		cout << "Case #" << (i+1) << ": " << solve(existingDirs, newDirs) << endl;
	}

	return 0;
}

vector<string> split(string input, char delimiter) {
	vector<string> result;
	stringstream ss(input);
	string token;

	while ( getline(ss, token, delimiter) ) {
		result.push_back(token);
	}

	return result;
}

int graphAdd(unordered_map<string, vector<string> > &graph, vector<string> split) {
	int count = 0;
	string parentDir = "";
	string currentDir = "";

	for ( unsigned int i = 1; i < split.size(); i++ ) {
		string currentDir = parentDir + "/" + split[i];

		if ( find(graph[parentDir].begin(), graph[parentDir].end(), currentDir) == graph[parentDir].end() ) {
			graph[parentDir].push_back(currentDir);
			vector<string> subDirs;
			graph[currentDir] = subDirs;
			count++;
		}

		parentDir = currentDir;
	}

	return count;
}

int solve(vector<string> &existingDirs, vector<string> &newDirs) {
	unordered_map<string, vector<string> > graph;

	vector<string> subDirs;
	graph[""] = subDirs;

	for ( vector<string>::iterator eit = existingDirs.begin(); eit != existingDirs
.end(); eit++ ) {
		string currentExistingDir = *eit;
		graphAdd(graph, split(currentExistingDir, '/'));
	}

	int count = 0;

	for ( vector<string>::iterator nit = newDirs.begin(); nit != newDirs
.end(); nit++ ) {
		string currentNewDir = *nit;
		count += graphAdd(graph, split(currentNewDir, '/'));
	}

	return count;
}
