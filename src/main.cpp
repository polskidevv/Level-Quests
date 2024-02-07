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

		if(auto menu = this->getChildByID("left-side-menu")) {
			if (Mod::get()->getSettingValue<bool>("active"))
				menu->addChild(button);
				menu->updateLayout();
		}

		return true;
	} 
};