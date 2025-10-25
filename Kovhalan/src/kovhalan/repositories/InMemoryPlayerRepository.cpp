#include "kovhalan/repositories/InMemoryPlayerRepository.hxx"

namespace kovhalan {
namespace repositories {
InMemoryPlayerRepository::InMemoryPlayerRepository() : stored_player_{} {}
std::shared_ptr<domain::Player> InMemoryPlayerRepository::getPlayer() const {
    if ( !stored_player_.has_value() ) {
        return nullptr;
    }
    return std::make_shared<domain::Player>( stored_player_.value() );
}

void InMemoryPlayerRepository::savePlayer( const domain::Player &aPlayer ) { stored_player_ = aPlayer; }
} // namespace repositories
} // namespace kovhalan
