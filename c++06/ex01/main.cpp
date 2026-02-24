#include "Serializer.hpp"
int main()
{
    Data data;
    data.name = "mohamed";
    data.age = 27;
    data.height = 1.75f;
    uintptr_t raw = Serializer::serialize(&data);
    std::cout << "Serialized data: " << raw << std::endl;
    Data *deserializedData = Serializer::deserialize(raw);
    std::cout << "Deserialized data: " << std::endl;
    std::cout << "Name: " << deserializedData->name << std::endl
              << "Age: " << deserializedData->age << std::endl
              << "Height: " << deserializedData->height << std::endl;
}