#pragma once

#include "kovhalan/use_cases/IPlayerRepository.hxx"

namespace kovhalan {
namespace repositories {
class InMemoryPlayerRepository : public use_cases::IPlayerRepository {
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
