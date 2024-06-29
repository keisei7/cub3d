# cub3D

## Usage
```bash
make
./cub3D map.cub
```
## arguments
*.cub  <a map cosists of the following elements>
- 0 : empty space
- 1 : wall

## OK functions
- open
- close
- read
- write
- printf
- malloc
- free
- perror
- strerror
- exit
- gettimeofday
- All functions of the math library (-lm man man 3 math)
- All functions of the MinilibX
- Libft functions

# TODO
- 描画関連
	- 壁は、向いてる方角に従って違うテクスチャ
		- XPMファイル？
	- 天井と床の色は、互いに違う二色
		- RGBで指定される
- window関連
	- <- -> で視点移動
	- W, A, S, D で移動
	- ESC でwindowを閉じて、プログラム終了(cleanly)
	- x でwindowを閉じて、プログラム終了(cleanly)
- マップ関連
	- マップが壁で囲まれてるチェック
	- 地図以外は、空行で区切れる　＝＞　空行を適切に無視する
	- 地図は常に最後
	- 地図以外の情報の順番にきまりはない
	- 地図以外の情報は、スペースで区切れる
	- 地図内のスペースは意味を持つ (地図全体の歪な形とか)
	- 地図のエラーの時は "Error\n ********" の出力


# ===== devlogs =====
### 2024/06/20 kisobe
- To compile, change "# include "../mlx-mms/mlx.h" in include/cub3d.h to # include "../mlx-linux/mlx.h"" and remove libmlx.dylib.
### 2024/06/21 kisobe
- Implemented event hook(W, A, S, D, ->, <-)
- floor and ceiling color
- wall collisions
- added event.c and move.c

### 2024/06/25 kmiyazaw
- 日本語で失礼します
- ブランチを分けました。
- 分けたブランチの先で、ft_err_printfをprintfに置き換えました。


