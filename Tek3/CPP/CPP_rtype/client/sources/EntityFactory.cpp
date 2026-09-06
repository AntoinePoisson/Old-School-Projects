#include "systems/EntityFactory.hpp"
#include <ctime>

void rtype::client::EntityFactory::createButton(const struct Button &button)
{
    struct rtype::component::Position pos(button.x, button.y);
    struct rtype::component::DisplayOrder display(rtype::component::drawOrder::THIRD);
    struct rtype::component::Sprite sprite(button.imagePath);
    struct rtype::component::ButtonAction act(button.action);
    struct rtype::component::Surface surface(button.width, button.height);
    // struct rtype::component::StartingTime start(std::time(nullptr));
    // struct rtype::component::SpriteSheet sheet(button.offset, button.nbSheet, button.duration, button.loop);


    Entity id = _ecMan.createEntity();
    if (button.fontPath.size()) {
        struct rtype::component::Text text(button.fontPath, button.textString, button.xTxt, button.yTxt, button.textSize);//TODO replace by text pos
        _ecMan.addComponents(id, pos, display, sprite, text, act, surface);/*, start);*/
    } else {
        _ecMan.addComponents(id, pos, display, sprite, act, surface);//, start);
    }
}

void rtype::client::EntityFactory::createButtons(const std::vector<struct Button> &buttons)
{
    for (auto it = buttons.begin(); it != buttons.end(); it++) {
        createButton(*it);
    }
}

const Entity rtype::client::EntityFactory::createSimpleImage(const struct Image &img)
{
    struct rtype::component::DisplayOrder display(img.order);
    struct rtype::component::Sprite sprite(img.path);
    struct rtype::component::Position pos(img.x, img.y);

    Entity id = _ecMan.createEntity();
    _ecMan.addComponents(id, sprite, display, pos);
    return (id);
}

const Entity rtype::client::EntityFactory::createSpriteSheet(const struct SpriteSheet &img)
{
    struct rtype::component::Position pos(img.x, img.y);
    struct rtype::component::Sprite sprite(img.imagePath);
    struct rtype::component::DisplayOrder display(img.order);
    struct rtype::component::StartingTime startT(std::chrono::system_clock::now());
    struct rtype::component::SpriteSheet sheet(img.offset, img.nbSheet, img.duration, img.loop);
    struct rtype::component::Surface surface(img.width, img.height);

    Entity id = _ecMan.createEntity();
    _ecMan.addComponents(id, pos, sprite, display, startT, sheet, surface);
    return (id);
}

void rtype::client::EntityFactory::createAudio(const Audio &aud, Entity &uuid)
{
    auto mus = std::make_shared<rtype::component::Music>(aud.path, aud.loop, aud.offset, aud.volume);
    rtype::component::Sound sound(aud.path, aud.loop, aud.offset, aud.volume);

    if (!uuid.size())
        uuid = _ecMan.createEntity();
    if (aud.music)
        _ecMan.addComponents(uuid, mus);
    else
        _ecMan.addComponents(uuid, sound);
}

void rtype::client::EntityFactory::createText(const Text &txt, Entity &uuid)
{
    std::cerr << "TEXT PATH = " << txt.path << std::endl;
    rtype::component::Text text(txt.path, txt.str, txt.x, txt.y, txt.size, txt.color, txt.style);

    if (!uuid.size())
        uuid = _ecMan.createEntity();
    _ecMan.addComponents(uuid, text);
}

void rtype::client::EntityFactory::createImage(const Image &img, Entity &uuid)
{
    std::cerr << "IMAGE PATH = " << img.path << std::endl;
    rtype::component::DisplayOrder order(img.order);
    rtype::component::Sprite sprite(img.path);

    if (!uuid.size())
        uuid = _ecMan.createEntity();
    _ecMan.addComponents(uuid, sprite, order);
}

void rtype::client::EntityFactory::createSpriteSheet(const SpriteSheet &img, Entity &uuid)
{
    rtype::component::SpriteSheet sheet(img.offset, img.nbSheet, img.duration, img.loop);

    // rtype::component::Position pos(img.x, img.y);
    // rtype::component::Sprite sprite(img.imagePath);
    // rtype::component::DisplayOrder display(img.order);
    // rtype::component::StartingTime startT(std::time(nullptr));
    // rtype::component::SpriteSheet sheet(img.offset, img.nbSheet, img.duration, img.loop);
    // rtype::component::Surface surface(img.width, img.height);

    if (!uuid.size())
        uuid = _ecMan.createEntity();
    createImage((Image){img.order, img.imagePath, img.x, img.y}, uuid);
    _ecMan.addComponent(uuid, sheet);
}
