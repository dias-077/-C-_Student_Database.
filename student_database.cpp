#include <iostream>
#include <vector>
#include <string>

class Student {
public:
    std::string name;
    int id;
    int age;

    Student(std::string name, int id, int age) : name(name), id(id), age(age) {}
};

class StudentDatabase {
private:
    std::vector<Student> students;

public:
    void addStudent(const std::string& name, int id, int age) {
        students.push_back(Student(name, id, age));
    }

    void removeStudent(int id) {
        for (auto it = students.begin(); it != students.end(); ++it) {
            if (it->id == id) {
                students.erase(it);
                break;
            }
        }
    }

    void printStudents() const {
        for (const auto& student : students) {
            std::cout << "ID: " << student.id << ", Name: " << student.name << ", Age: " << student.age << std::endl;
        }
    }
};

int main() {
    StudentDatabase db;
    db.addStudent("Alice", 101, 20);
    db.addStudent("Bob", 102, 21);
    db.addStudent("Charlie", 103, 22);

    std::cout << "Student Database:\n";
    db.printStudents();

    std::cout << "\nRemoving student with ID 102...\n";
    db.removeStudent(102);

    std::cout << "Updated Student Database:\n";
    db.printStudents();

    return 0;
}
