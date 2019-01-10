#pragma once

/*

// things I want to save but am not currently using

// fov and rotation visualized
	InitWindow(500, 500, "fov");
	SetTargetFPS(60);

	vec2 enemPos = { 250, 250 };
	float enemSpeed = 150.0f;
	float enemRot = 0.0f; // deg, rot cw
	float enemRotSpeed = 50.0f;
	float fov = 60.0f; // deg
	int fovLen = 100; // i could draw arc with bezier curve

	vec2 orig = { 1, 0 };

	float a = orig.angleBetween(vec2(-1, 0));

	while (!WindowShouldClose()) {

		// left
		if (IsKeyDown(KEY_A))
		{
			enemRot -= enemRotSpeed * GetFrameTime();
		}
		// right
		if (IsKeyDown(KEY_D))
		{
			enemRot += enemRotSpeed * GetFrameTime();
		}
		// forwards
		if (IsKeyDown(KEY_W))
		{
			enemPos += orig.getRotated(enemRot) * enemSpeed * GetFrameTime();
		}


		BeginDrawing();
		ClearBackground(GRAY);

		// enem
		vec2 pl = orig.getRotated(fov / -2 + enemRot) * fovLen; // point left
		vec2 pr = orig.getRotated(fov / 2 + enemRot) * fovLen; // point right
		DrawLineV(enemPos, enemPos + pl, BLACK);
		DrawLineV(enemPos, enemPos + pr, BLACK);
		// so enem overlaps
		DrawCircleV(enemPos, 10, BLUE);

		// arc
		vec2 offset = orig.getRotated(enemRot) * fovLen * 1.2; // math for correct scale?
		vec2 prev = pl;
		for (float i = 0; i < 1; i += 0.01f)
		{
			vec2 next = quadraticBezier(pl, offset, pr, i);
			DrawLineV(prev + enemPos, next + enemPos, BLACK);
			prev = next;
		}
		// test
		// DrawLineV(enemPos, orig * fovLen + enemPos, BLACK);

		EndDrawing();
	}

	CloseWindow();

// particle effect

	InitWindow(800, 800, "particle effect");
	SetTargetFPS(60);

	particleSpawner ps;

	while (!WindowShouldClose()) {

	ps.update();

	BeginDrawing();
	ClearBackground(GRAY);

	ps.draw();

	EndDrawing();
	}

	CloseWindow();

	// random visualization

	InitWindow(700, 700, "rand");

	randGen<float> r;
	r.seedRand(123456);

	bool notYet = true;

	const int num = 100; // 100 shows a good spread
	int vals[num];
	int vals2[num];
	for (int i = 0; i < num; i++) {
	vals[i] = r.rand(100, 600);
	vals2[i] = lerp1(100, 600, r.randDecimal(0.000, 1.000));

	// check for repeat
	for (int j = 0; j < i; j++) {
	if (vals[i] == vals[j] && notYet)
	{
	notYet = false;
	// idx where they repeat
	std::cout << i << std::endl;
	// std::abort();
	}
	}
	}
	int idx = 0;
	float elapsedTime = 0.0f;
	float delay = 0.2f;

	vec2 enemPos = { 0, 0 };
	vec2 enemStart = enemPos;
	bool atDest = false;
	vec2 enemDest = enemPos;
	float enemDist = 1.0f;

	vec2 enem2Pos = { 350, 350 };
	vec2 enem2Move = { 0, 0 };
	int enem2MaxDelta = 20;
	float enem2Elapsed = 0.0f;
	float enem2Delay = 1.0f;

	test myGuy;

	while (!WindowShouldClose())
	{
	elapsedTime += GetFrameTime();
	if (elapsedTime >= delay && idx < num - 1) {
	elapsedTime = 0;
	idx++;
	}

	enemDist += GetFrameTime() / 2;
	if (enemDist > 1) {
	enemDist = 0.0f;
	enemStart = enemDest;
	enemDest = vec2(r.rand(100, 600), r.rand(100, 600));
	}
	enemPos = lerp1(enemStart, enemDest, enemDist);
	if (enemPos == enemDest) {
	// enemDest = vec2(r.rand(100, 600), r.rand(100, 600));
	}

	enem2Elapsed += GetFrameTime();
	if (enem2Elapsed >= enem2Delay) {
	enem2Elapsed = 0;
	// enem2
	enem2Move.x += r.rand(-1 * enem2MaxDelta, enem2MaxDelta);
	enem2Move.y += r.rand(-1 * enem2MaxDelta, enem2MaxDelta);
	}


	enem2Pos += enem2Move.normalize() * GetFrameTime() * 100.0f;;
	// wrap
	if (enem2Pos.x > GetScreenWidth() + 5) {
	enem2Pos.x = -5;
	}
	if (enem2Pos.x < -5) {
	enem2Pos.x = GetScreenWidth() + 5;
	}
	if (enem2Pos.y > GetScreenHeight() + 5) {
	enem2Pos.y = -5;
	}
	if (enem2Pos.y < -5) {
	enem2Pos.y = GetScreenHeight() + 5;
	}

	myGuy.update();

	BeginDrawing();

	ClearBackground(WHITE);
	for (int i = 0; i < idx; i++)
	{
	DrawCircle(vals[i], 100, 2, BLACK);
	DrawCircle(vals2[i], 200, 2, BLACK);
	}
	DrawText(std::to_string(idx + 1).c_str(), 20, 20, 5, BLACK);
	// dot line bounds
	DrawCircle(100, 100, 3, RED);
	DrawCircle(100, 200, 3, RED);
	DrawCircle(600, 100, 3, RED);
	DrawCircle(600, 200, 3, RED);
	// titles
	DrawText("rand", 50, 100, 5, BLACK);
	DrawText("dec rand", 50, 200, 5, BLACK);

	DrawRectangleV(enemDest, {5, 5}, RED);
	DrawCircleV(enemPos, 5, GREEN);
	DrawText("rand pnt gen", enemDest.x + 5, enemDest.y + 5, 5, BLACK);

	DrawCircleV(enem2Pos, 5, BLUE);

	std::string seedS = "Seed: " + std::to_string(r.getSeed());
	DrawText(seedS.c_str(), 600, 10, 10, BLACK);

	myGuy.draw();

	EndDrawing();
	}

	CloseWindow();


// curves and splines

	InitWindow(700, 700, "curves and splines");
	SetTargetFPS(60);

	// guyAngle

	vec2 pts[10];
	int rad = 5;
	for (int i = 0; i < 10; i++)
	{
	pts[i].x = cos(360 / 10 * i * DEG_TO_RAD) * 200 + GetScreenWidth() / 2;
	pts[i].y = sin(360 / 10 * i * DEG_TO_RAD) * 200 + GetScreenHeight() / 2;
	}
	float cur = 0.0f;
	int curMod = 1;

	vec2 p1 = { 100, 100 };
	vec2 p2 = { 100, 600 };
	vec2 p3 = { 600, 600 };

	vec2 guyPos = p1;
	float guyT = 0.0f;
	int guyDir = 1;
	Texture2D guySprite = LoadTexture("fish.png");
	float guyAngle = 0.0f;

	while (!WindowShouldClose())
	{
	if (cur <= 0 || cur >= 1) {
	curMod *= -1;
	}
	cur += GetFrameTime() * curMod / 2;
	if (cur < 1)
	{
	// cur += GetFrameTime() * curMod / 2;
	}

	// check collision
	for (int i = 0; i < 10; i++)
	{
	// move pnt
	if (IsMouseButtonDown(0) && CheckCollisionPointCircle(GetMousePosition(), pts[i], rad)) {
	pts[i] = GetMousePosition();
	}
	}

	float prevGuyT = guyT;
	if (guyT > 1 || guyT < 0)
	{
	guyDir *= -1;
	}
	guyT += GetFrameTime() * guyDir / 5;
	guyPos = quadraticBezier(p1, p2, p3, guyT);
	// angle between starting and ending vectors, multiplied by current scale between,
	// converted to degrees, flipped negatively, scaled to half, rotated for correct direction
	guyAngle = vec2(-1, 0).angleBetween(vec2(1, 0)) * guyT * RAD_TO_DEG / -2 + 90;

	BeginDrawing();

	ClearBackground(WHITE);

	for (int i = 0; i < 10; i++)
	{
	DrawCircleV(pts[i], rad, BLACK);
	DrawText(std::to_string(i+1).c_str(), pts[i].x+5, pts[i].y+5, 5, BLACK);

	for (float j = 0; j < cur; j += 0.02)
	{
	int cur = i;
	int next = i + 1;
	int prev = i - 1;
	if (next > 9) {
	next = 0;
	}
	if (prev < 0) {
	prev = 9;
	}

	DrawPixelV(quadraticBezier(pts[prev], pts[cur], pts[next], j), BLACK);
	}
	}

	DrawTextureEx(guySprite, guyPos, guyAngle, 1.0f, WHITE);
	DrawCircleV(p1, 3, GREEN);
	DrawCircleV(p2, 3, GREEN);
	DrawCircleV(p3, 3, GREEN);

	EndDrawing();
	}

	UnloadTexture(guySprite);
	CloseWindow();

// lerping visualization

	InitWindow(700, 800, "lerp");
	SetTargetFPS(60);

	// particle spawner and ui transitions not done

	float scale = 0.0f;
	Rectangle rec1 = { 0, 0, 10, 10 };

	vec2 pos1 = { 300, 100 };
	vec2 pos2 = { 300, 200 };
	vec2 dest1 = { 600, 100 };
	vec2 dest2 = { 600, 200 };

	vec2 waypoints[10];
	for (int i = 0; i < 10; i++)
	{
	waypoints[i] = { (float)GetRandomValue(10, 290), (float)GetRandomValue(10, 290) };
	}
	int carryOver = 0;
	int curIdx = 0;

	float enemyCurrentHealth = 250.0f;
	float enemyMaxHealth = 250.0f;
	Rectangle enemyHealthBar = { 50, 700, 600, 50 };
	int hitDir = -1;

	Texture2D testParticle = LoadTexture("fish.png");
	Color particleR = RED; // r = red
	Color particleG = GRAY; // g = gray
	Color particleC = RED; // c = current
	float colScale = 0.0f;
	int colDir = 1;

	particle guy1;
	guy1.pos = { 550, 450 };

	while (!WindowShouldClose())
	{
	scale += GetFrameTime() / 10;
	// pos1 = lerp1(pos1, dest1, scale);
	pos1 = easeInSine(scale, pos1, dest1 - pos1, 2.0f); // t = elapsed time
	// pos1.x = -easeInOutBack(scale, pos1.x, 600, 2.0f);
	pos2 = lerp2(pos2, dest2, scale);

	// carryOver++;
	if (scale > 1.0f)
	{
	scale = 0.0f;
	// carryOver = 0;
	curIdx++;
	}
	int nextIdx = curIdx + 1;
	if (nextIdx > 9)
	{
	nextIdx = 0;
	}
	if (curIdx > 9)
	{
	curIdx = 0;
	}

	if (enemyCurrentHealth <= 0 || enemyCurrentHealth >= enemyMaxHealth)
	{
	hitDir *= -1;
	}
	enemyCurrentHealth += hitDir * GetFrameTime() * 50;

	if (colScale >= 1 || colScale <= 0){
	colDir *= -1;
	}

	colScale += colDir * GetFrameTime() / 2;
	particleC.r = lerp2(particleR.r, particleG.r, colScale);
	particleC.g = lerp2(particleR.g, particleG.g, colScale);
	particleC.b = lerp2(particleR.b, particleG.b, colScale);

	guy1.update();

	BeginDrawing();

	ClearBackground(WHITE);

	DrawRectangle(pos1.x, pos1.y, rec1.width, rec1.height, BLUE);
	DrawRectangle(pos2.x, pos2.y, rec1.width, rec1.height, BLUE);

	vec2 temp = lerp2(waypoints[curIdx], waypoints[nextIdx], scale);
	DrawRectangle(temp.x, temp.y, 10, 10, PURPLE);

	for (int i = 0; i < 10; i++)
	{
	DrawRectangle(waypoints[i].x, waypoints[i].y, 3, 3, BLACK);
	DrawText(std::to_string(i+1).c_str(), waypoints[i].x + 5, waypoints[i].y + 5, 5, BLACK);
	}

	DrawRectangleRec(enemyHealthBar, BLACK);
	int newWidth = lerp2(0.0f, enemyHealthBar.width - 10, enemyCurrentHealth / enemyMaxHealth);
	DrawRectangle(enemyHealthBar.x + 5, enemyHealthBar.y + 5, newWidth, enemyHealthBar.height - 10, GREEN);
	std::string s = std::to_string((int)enemyCurrentHealth) + " / " + std::to_string((int)enemyMaxHealth);
	DrawText(s.c_str(), 50, 670, 20, BLACK);

	DrawTextureEx(testParticle, { 250, 350 }, 0.0f, 3.0f, particleC);

	guy1.draw();

	EndDrawing();
	}

	UnloadTexture(testParticle);
	CloseWindow();

// sin cos (not fully functional

	InitWindow(800, 800, "sincos");
	SetTargetFPS(60);

	myCircle c;
	float y = 600.0f;
	float wave = 0.0f;

	const int num = 400;
	vec2 pts[num];
	for (int i = 0; i < num; i++) {
	pts[i] = { (float)i * 2, (float)y };
	wave += 0.1; // this stuff right here
	y += sin(wave);
	}

	while (!WindowShouldClose()) {

	// c.update();


	BeginDrawing();
	ClearBackground(WHITE);

	// c.draw();

	DrawText(std::to_string(c.rad).c_str(), 10, 10, 20, BLACK);

	for (int i = 0; i < num; i++) {
	DrawCircle(pts[i].x, pts[i].y, 1, PURPLE);
	}

	EndDrawing();
	}

	CloseWindow();

// something with vectors (not fully functional)

	InitWindow(500, 600, "Vectors");
	SetTargetFPS(60);

	enem e;
	player p;

	while (!WindowShouldClose()) {

	e.update();
	p.update();

	BeginDrawing();
	ClearBackground(WHITE);

	e.draw();
	p.draw();

	EndDrawing();
	}

	CloseWindow();

// not sure (not fully functional)

	InitWindow(400, 600, "WrapText");

	std::string txt = "abc def ghi jkl mno pqr stu vwx yz";
	std::string c = "0";

	std::string dist = "x, y";

	ball b;
	vec2 distFromPlayer;

	while (!WindowShouldClose()) {

	// bounds checking for big long line

	// line spacing
	int mod = 10;
	// current pos to draw
	vec2 pos(mod, mod);
	// clipping values
	vec2 max(GetScreenWidth() / 2, GetScreenHeight());

	b.update();
	if (IsMouseButtonDown(0)) {
	distFromPlayer = { (float)GetMouseX(), (float)GetMouseY() };
	}

	BeginDrawing();
	ClearBackground(BLACK);

	for (int i = 0; i < txt.size(); i++) {
	// c = txt[i] + "\0"; // this doesn't work

	// get next word
	c = txt[i];
	c += "\0";

	dist = std::to_string(b.pos.x - distFromPlayer.x) +
	", " + std::to_string(b.pos.y - distFromPlayer.y);

	// DrawText(c.c_str(), pos.x, pos.y, 5, RAYWHITE);
	b.draw();
	DrawCircle(distFromPlayer.x, distFromPlayer.y, 5, BLUE);
	DrawText(dist.c_str(), 10, 10, 10, WHITE);

	// increment
	pos.x += mod;

	// bounds
	if (pos.x >= max.x) {
	pos.x = mod;
	pos.y += mod;
	}
	}

	EndDrawing();
	}

	CloseWindow();

*/