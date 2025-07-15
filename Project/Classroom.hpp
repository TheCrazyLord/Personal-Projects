#pragma once
#include <cstdint>
#include <string>
#include <vector>
#include "Person.hpp"

class Classroom
{
  public:
    Classroom(std::uint32_t aClassId, std::uint32_t aTeacherId,
              std::string classDescription, std::uint32_t studentCount) : ClassId(aClassId), teacherId(aTeacherId), classDesc(classDescription), studentCnt(studentCount) {};

    void addStudent(Person theStudent);

    std::vector<Person> getStudentList();
    std::uint32_t getTeacherId();
    std::uint32_t getClassId();

    uint32_t getId();
    void printClassDetails() const;

  private:
  std::uint32_t ClassId {};
  std::uint32_t teacherId{};
  std::string classDesc {""};
  std::uint32_t studentCnt {};
  std::vector<Person> listOfStudents {};

};
