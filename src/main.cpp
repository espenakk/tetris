#include <threepp/threepp.hpp>

using namespace threepp;

int main() {
    Canvas canvas("Tetris");
    GLRenderer glr(canvas.size());

    auto scene = Scene::create();
    auto camera = PerspectiveCamera::create();
    camera->position.z = 20;

    glr.setClearColor(Color::salmon);

    //    canvas.onWindowResize([&](WindowSize size) {
    //        camera->aspect = size.aspect();
    //        camera->updateProjectionMatrix();
    //        glr.setSize(size);
    //    });

    Clock clock;
    canvas.animate([&] {
        float dt = clock.getDelta();
        glr.render(*scene, *camera);
    });

    return 0;
}