#include <Geode/Geode.hpp>
#include <Geode/modify/LevelInfoLayer.hpp>

using namespace geode::prelude;

class $modify(InfoLayerMy, LevelInfoLayer) {
	void onButton(CCObject* target) {
		auto scene = reinterpret_cast<CCNode*>(CCScene::get());
		auto questsMenu = ChallengesPage::create();
		questsMenu->setZOrder(1);
		questsMenu->draw();
		questsMenu->setVisible(true);
		scene->addChild(questsMenu);
	}

	bool init(GJGameLevel* p0, bool p1) {

		if (!LevelInfoLayer::init(p0, p1))
			return false;

		auto buttonSpr = CCSprite::create("challengeButton.png"_spr);
		auto button = CCMenuItemSpriteExtra::create(
			buttonSpr, this, menu_selector(InfoLayerMy::onButton)
		);

		button->setZOrder(2);
		button->setPosition(760, 11);
		auto menu = CCMenu::create();
		menu->addChild(button);
		menu->setPosition(-165, 235.5);
		menu->setScale(0.675);
		this->addChild(menu);
		return true;
	} 
};