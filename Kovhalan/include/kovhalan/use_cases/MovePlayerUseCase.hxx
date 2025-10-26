#pragma once

#include "kovhalan/kovhalan.hxx"
#include "kovhalan/domain/IMapValidator.hxx"
#include "kovhalan/use_cases/IPlayerRepository.hxx"

namespace kovhalan {
namespace use_cases {
/*!
 * \brief プレイヤーを移動させるユースケース
 */
class MovePlayerUseCase {
 public:
    explicit MovePlayerUseCase( std::shared_ptr<IPlayerRepository>     playerRepository,
                                std::shared_ptr<domain::IMapValidator> mapValidator );

 public:
    /*!
     * \brief プレイヤーを指定された座標に移動させる
     * \param x 移動先のX座標
     * \param y 移動先のY座標
     * \return 移動が成功した場合はtrue、失敗した場合はfalse
     */
    bool execute( std::uint32_t x, std::uint32_t y );

 private:
    std::shared_ptr<IPlayerRepository>     player_repository_;
    std::shared_ptr<domain::IMapValidator> map_validator_;
};
} // namespace use_cases
} // namespace kovhalan
