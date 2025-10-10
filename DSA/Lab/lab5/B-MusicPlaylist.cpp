#include <iostream>
using namespace std;

struct Song {
    string name;
    Song* next;
    Song* prev;

    Song(const string& n) : name(n), next(NULL), prev(NULL) {}
};

class Playlist {
    Song* current;

public:
    Playlist() : current(NULL) {}

    ~Playlist() {
        if (!current) return;

        Song* start = current;
        Song* temp = current->next;
        current->prev->next = NULL; 

        while (temp) {
            Song* next = temp->next;
            delete temp;
            temp = next;
        }
        delete start;
    }

    void addSong(const string& name) {
        Song* newSong = new Song(name);
        if (!current) {
            newSong->next = newSong->prev = newSong;
            current = newSong;
        } else {
            Song* last = current->prev;
            last->next = newSong;
            newSong->prev = last;
            newSong->next = current;
            current->prev = newSong;
        }
        cout << "Added song: " << name << endl;
    }

    void removeSong(const string& name) {
        if (!current) {
            cout << "Playlist is empty.\n";
            return;
        }
        Song* temp = current;
        do {
            if (temp->name == name) {
                if (temp->next == temp) {
                    delete temp;
                    current = NULL;
                    cout << "Removed song: " << name << endl;
                    return;
                }
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
                if (temp == current) current = temp->next;
                delete temp;
                cout << "Removed song: " << name << endl;
                return;
            }
            temp = temp->next;
        } while (temp != current);
        cout << "Song \"" << name << "\" not found\n";
    }

    void playNext() {
        if (current) {
            current = current->next;
            cout << "Playing: " << current->name << endl;
        } else {
            cout << "Playlist is empty.\n";
        }
    }

    void playPrevious() {
        if (current) {
            current = current->prev;
            cout << "Playing: " << current->name << endl;
        } else {
            cout << "Playlist is empty.\n";
        }
    }

    void showCurrent() {
        if (current)
            cout << "Now Playing: " << current->name << endl;
        else
            cout << "Playlist is empty.\n";
    }
};

int main() {
    Playlist pl;
    int choice;
    string name;

    do {
        cout << "\nMusic Playlist Menu ---\n";
        cout << "1. Add Song\n2. Remove Song\n3. Play Next\n4. Play Previous\n5. Show Current\n0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore(); 
        switch (choice) {
            case 1:
                cout << "name: ";
                getline(cin, name);
                pl.addSong(name);
                break;
            case 2:
                cout << "Enter song remove: ";
                getline(cin, name);
                pl.removeSong(name);
                break;
            case 3:
                pl.playNext();
                break;
            case 4:
                pl.playPrevious();
                break;
            case 5:
                pl.showCurrent();
                break;
            case 0:
                cout << "Exiting\n";
                break;
            default:
                cout << "Invalid choice\n";
        }
    } while (choice != 0);
    return 0;
}
