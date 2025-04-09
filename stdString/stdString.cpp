#include <iostream>
#include <string>

auto Lorem = R"(

Lorem ipsum dolor sit amet, consectetur adipiscing elit. Nulla non libero id sem luctus tincidunt sit amet vel sem. Curabitur velit ligula, porttitor eu metus vitae, viverra ullamcorper neque. Mauris rutrum justo at diam eleifend vulputate nec et odio. Curabitur pulvinar faucibus lacus nec congue. Integer ultricies nibh quis eros efficitur, non ullamcorper arcu facilisis. Nam eget dictum massa, et euismod elit. Donec congue ornare pretium. Proin tempor mi et odio rhoncus, a aliquam enim accumsan. Proin facilisis diam a elementum porttitor. Proin turpis lorem, dictum sit amet risus sit amet, eleifend convallis neque. Interdum et malesuada fames ac ante ipsum primis in faucibus. Vivamus fermentum posuere metus, viverra iaculis arcu porttitor scelerisque. Donec eget arcu eu sapien ultrices consequat. Donec gravida luctus enim, et viverra magna ultricies aliquam. Donec nec lorem vel enim scelerisque scelerisque. Aliquam finibus hendrerit arcu, eget lobortis nulla.

Maecenas ex metus, semper id fermentum vitae, porttitor vitae diam. Donec ornare risus nibh, sed iaculis elit dignissim et. Proin metus diam, molestie quis interdum vel, gravida sed nisi. In lectus ligula, rutrum in libero ut, sollicitudin dapibus augue. Quisque interdum aliquam metus, varius vehicula nulla auctor vel. Etiam sollicitudin, est nec maximus ornare, neque diam dignissim augue, nec cursus quam sapien sed velit. Praesent lacinia gravida fringilla. Proin enim arcu, sollicitudin a egestas sed, lacinia at arcu. Nam eleifend quis odio nec iaculis. Duis quis dictum est.

Aliquam feugiat metus sed nunc interdum, vitae tempus lectus luctus. Mauris scelerisque tortor ac iaculis semper. Mauris tellus sem, aliquam eget enim sed, porttitor lobortis justo. Pellentesque ornare neque eu tortor lobortis hendrerit. In hac habitasse platea dictumst. In hac habitasse platea dictumst. Nulla dictum dapibus libero, vitae molestie enim fringilla eget. Class aptent taciti sociosqu ad litora torquent per conubia nostra, per inceptos himenaeos. Duis sit amet ultricies orci. Ut eget rhoncus justo. Nulla eget ligula felis. Quisque nec dui elit. In dignissim libero nibh.

Sed sollicitudin, massa tempor pharetra varius, ante ligula condimentum magna, id porttitor lorem eros sit amet libero. Aenean at lorem ac nulla luctus iaculis mollis eget augue. Pellentesque lacus odio, volutpat id velit eu, facilisis porta elit. Fusce pretium nec lorem id varius. Sed posuere mi vel neque faucibus vulputate. Aenean ut turpis non lorem iaculis vehicula. Cras semper erat id neque ornare pretium. Pellentesque quis erat luctus nisl aliquam fermentum.)";

int main(int argc, char* argv[])
{
    std::string Str = "Hello world!";

    // Str += "!!";
    // Str.append("!!");
    // Str.operator+=("!!");

    // Str.pop_back();

    // Str.erase(6, 5);

    // std::cout << Str.length() << '\n';
    // std::cout << Str.size() << '\n';

    size_t result = Str.find("world");
    size_t result2 = Str.rfind('l');
        
    std::cout << result << '\n';
    std::cout << result2 << '\n';

    Str.insert(5, " beautiful");
    Str.append(Lorem);

    Str.erase(50);
    
    std::cout << Str << '\n';

    std::cout << Str.length() << '\n';
    std::cout << Str.capacity() << '\n';

    Str.shrink_to_fit();
    
    std::cout << "after: " << Str.capacity() << '\n';

    std::string sub = Str.substr(0, 5);

    std::cout << sub << '\n';
    
    return 0;
}
