#pragma once

#include "kovhalan/repositories/IPlayerRepository.hxx"

namespace kovhalan {
namespace repositories {
class InMemoryPlayerRepository : public IPlayerRepository {
 public:
    InMemoryPlayerRepository();

 public:
    std::shared_ptr<domain::Player> getPlayer() const override;

    void                            savePlayer( const domain::Player &aPlayer ) override;

 private:
    std::optional<domain::Player> stored_player_;
};
} // namespace repositories
} // namespace kovhalan
