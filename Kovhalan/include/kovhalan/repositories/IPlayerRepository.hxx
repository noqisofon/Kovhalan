#pragma once

#include "kovhalan/domain/Player.hxx"

namespace kovhalan {
namespace repositories {
/*!
 * \brief プレイヤーリポジトリのインターフェース
 */
class IPlayerRepository {
 protected:
    IPlayerRepository() = default;

 public:
    virtual ~IPlayerRepository() = default;

 public:
    virtual std::shared_ptr<domain::Player> getPlayer() const                           = 0;

    virtual void                            savePlayer( const domain::Player &aPlayer ) = 0;
};
} // namespace repositories
} // namespace kovhalan
