#include <bits/stdc++.h>
#define loopd(i, ii, ff) for(i = int( ii ); i >= int( ff ); i--)
#define loop(i, ii, ff) for(i = int( ii ); i < int( ff ); i++)
#define MIN(x, y) ((x) < (y) ? (x) : (y))
#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define ABS(x) MAX((x), -(x))
#define INRANGE(v, min, max) ((min) <= (v) && (v) <= (max))
#define RANGE(v, min, max) MAX(MIN((v), (max)), (min))
#define DEC(v, n) (v = ((v) + (n) - 1) % (n))
#define INC(v, n) (v = ((v) +1) % (n))
#define F first
#define S second
#define PB push_back
#define SZ 5
#define BUFFSZ 5000
#define INF 1000000000

using namespace std;

typedef struct line line;
typedef struct cell cell;
typedef struct board board;

typedef map<int, cell *> mii;
typedef vector<cell *> vi;

struct cell {
	bool marked;
	int value;
	line * row;
	line * col;

	cell() {
		marked = false;
		row = nullptr;
		col = nullptr;
	}
};

struct line {
	vector<cell *> cells;
	int marked;

	line() {
		marked = 0;
	}

	bool mark() {
		if(marked < int( cells.size() )) {
			marked++;
		}

		return marked == int( cells.size() );
	}
};

struct board {
	vector<line *> rows;
	vector<line *> cols;
	cell * cells[SZ][SZ];
	mii mapping;

	board() {
		int i, j;

		memset(cells, 0, sizeof(cells));

		loop(i, 0, SZ){
			loop(j, 0, SZ) {
				cell * nc = new cell;
				cells[i][j] = nc;
			}
		}

		loop(i, 0, SZ) {
			line * row = new line;
			loop(j, 0, SZ) {
				cell * c = cells[i][j];
				row->cells.PB(c);
				c->row = row;
			}
			rows.PB(row);
		}

		loop(j, 0, SZ) {
			line * col = new line;
			loop(i, 0, SZ) {
				cell * c = cells[i][j];
				col->cells.PB(c);
				c->col = col;
			}
			cols.PB(col);
		}
	}

	void add(int i, int j, int value) {
		assert(0 <= i && i < SZ);
		assert(0 <= j && j < SZ);

		cell * c = cells[i][j];
		c->value = value;
		mapping[value] = c;
	}

	cell * get(int i, int j) {
		assert(0 < i && i < SZ);
		assert(0 < j && j < SZ);

		return cells[i][j];
	}

	bool mark(int value) {
		bool is_winner = false;

		if (mapping.count(value) != 0) {
			cell * c = mapping[value];
			if (c->marked == false){
				c->marked = true;
				is_winner = c->row->mark();
				is_winner = is_winner || c->col->mark();
			}
		}

		return is_winner;
	}

	void print() {
		int i, j;
		loop(i, 0, SZ) {
			loop(j, 0, SZ) {
				printf("%d ", cells[i][j]->value);
			}
			printf("\n");
		}
	}

	int score(int last_number) {
		int unmarked = 0;
		int i, j;
		loop(i, 0, SZ) {
			loop(j, 0, SZ) {
				cell * c = cells[i][j];

				unmarked += c->marked ? 0 : c->value;
			}
		}

		return unmarked * last_number;
	}

	~board() {
		int i, j;
		loop(i, 0, SZ) {
			loop(j, 0, SZ) {
				if (cells[i][j] != nullptr) {
					delete cells[i][j];
					cells[i][j] = nullptr;
				}
			}
		}

		// TODO rows
		// TODO cols
	}
};

char buff[BUFFSZ];

void read_queue(queue<int> &q) {
	fgets(buff, BUFFSZ, stdin);
	const char * sep = ",";
	char * tok = strtok(buff, sep);
	int v;
	while(tok != NULL) {
		sscanf(tok, "%d", &v);
		q.push(v);
		tok = strtok(NULL, sep);
	}
}

void read_boards(vector<board *> &boards) {
	int i, j, v;
	while(fgets(buff, BUFFSZ, stdin) != NULL) {
		int len = strlen(buff);
		assert(len == 0 || (len == 1 && buff[0] == '\n'));

		board * nb = new board;
		loop(i, 0, SZ) {
			loop(j, 0, SZ) {
				if ( scanf("%d", &v) == EOF ) {
					return;
				}
				nb->add(i, j, v);
			}
		}

		boards.PB(nb);
	}
}


void cleanup(vector<board *> &boards) {
	int i;
	loop(i, 0, boards.size()) {
		board * b = boards[i];
		if (b != nullptr) {
			delete b;
			boards[i] = nullptr;
		}
	}
}

int main() {
	queue<int> q;
	vector<board *> boards;

	read_queue(q);
	read_boards(boards);

	int i;
	loop(i, 0, boards.size()) {
		boards[i]->print();
		printf("\n");
	}

	board * winner = nullptr;
	int last_number;
	while(winner == nullptr && !q.empty()) {
		const int value = q.front(); q.pop();
		int i;
		loop(i, 0, boards.size()) {
			board * b = boards[i];
			bool win = b->mark(value);

			if (win) {
				winner = b;
				last_number = value;
				break;
			}
		}
	}

	assert(winner != nullptr);

	int score = winner->score(last_number);
	printf("%d\n", score);

	cleanup(boards);
	return 0;
}
