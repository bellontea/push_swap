NAME	=   push_swap
HEADER  =   push_swap.h

SRCS_COMMS = $(shell ls ./commands/*.c)

SRCS_UTILS =   $(shell ls ./utils/*.c)

SRCS_SORT	=	$(shell ls ./sort/*.c)

SRCS		=   ${SRCS_UTILS} ${SRCS_COMMS} ${SRCS_SORT} $(shell ls ./*.c)

CFLAGS	= -Wall -Wextra -Werror

RM		= rm -rf

CC		=   gcc

OBJS	=	$(SRCS:%.c=%.o)

ARG		=	$(shell ruby -e "puts (1..100).to_a.shuffle.join(' ')")
#ARG			= 10 348 135 293 51 53 44 341 244 369 287 4 444 151 317 210 184 121 485 473 241 61 330 25 71 114 162 371 46 274 397 62 67 431 176 26 379 157 132 247 288 88 363 410 164 493 477 77 279 238 296 43 222 375 269 31 448 386 450 499 454 253 301 21 56 231 204 336 456 275 359 182 94 211 102 55 484 103 372 357 349 140 328 167 73 340 459 258 360 195 289 492 281 352 436 49 419 97 14 234 263 282 45 92 358 60 123 265 331 57 412 180 401 152 377 408 104 417 319 500 147 382 221 362 143 39 187 9 264 243 426 441 342 197 185 168 27 37 451 155 307 443 393 169 423 273 472 277 63 327 109 280 24 465 434 335 421 294 171 111 130 489 402 399 299 468 278 475 35 226 42 283 3 325 118 50 28 129 413 471 189 232 5 318 95 68 223 483 212 242 175 476 257 312 145 418 174 304 170 220 376 338 354 186 250 270 370 115 261 76 344 333 467 177 285 199 80 83 30 425 251 373 146 409 428 395 12 163 202 254 284 387 321 495 89 142 34 290 120 252 496 203 486 324 105 201 245 481 309 398 138 107 205 122 407 308 310 297 112 219 437 188 75 90 424 380 461 415 32 82 228 248 469 230 364 246 127 458 181 237 422 166 85 452 156 267 17 149 462 96 300 72 430 416 40 98 262 455 323 200 33 368 384 298 133 64 106 117 161 474 291 420 438 41 482 48 405 322 8 91 355 292 93 353 125 361 356 449 314 435 326 429 339 259 194 442 229 383 69 256 191 131 209 487 134 213 225 148 108 18 172 216 47 84 406 389 224 79 404 119 38 432 381 266 7 6 52 153 351 311 313 70 394 36 13 315 100 268 154 19 391 320 126 439 276 466 347 178 470 11 390 65 345 239 137 29 447 227 479 116 388 124 159 334 215 236 158 150 165 306 392 400 249 110 193 58 87 457 446 59 346 141 101 16 99 196 198 136 337 86 491 460 2 367 332 478 445 218 173 128 427 366 433 396 255 305 316 183 113 214 1 22 463 81 411 260 464 374 271 403 144 207 286 494 440 453 74 78 240 378 329 54 480 350 206 66 385 190 15 295 233 414 192 208 497 303 139 365 302 272 235 498 160 490 343 217 179 23 488 20
all:		$(NAME)

$(NAME):	${OBJS} $(HEADER)
			$(CC) -o $(NAME) ${OBJS}

%.o: 		%.c	
			$(CC) $(CFLAGS) -I./ -c $< -o $@

clean:
			$(RM) ${OBJS}

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

test:		
			make -s && make -s  clean && ./push_swap $(ARG)

.PHONY: clean fclean re