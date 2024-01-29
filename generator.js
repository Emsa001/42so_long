const fs = require('fs');

function Maze(width, height) {
    this.width = width;
    this.height = height;
    this.grid = [];
    this.directions = [[-1, 0], [1, 0], [0, -1], [0, 1]];

    // Initialize the grid with walls
    for (let i = 0; i < height; i++) {
        this.grid[i] = [];
        for (let j = 0; j < width; j++) {
            this.grid[i][j] = '1';
        }
    }

    // Start position
    this.grid[1][1] = 'P';

    // Generate the maze from the start position
    this.generateMaze(1, 1);

    // Exit position
    this.grid[height - 2][width - 2] = 'E';
}

Maze.prototype.generateMaze = function(x, y) {
    let directions = this.directions.sort(() => Math.random() - 0.5);

    for (let i = 0; i < directions.length; i++) {
        let dx = x + directions[i][0] * 2;
        let dy = y + directions[i][1] * 2;

        if (dx > 0 && dx < this.height - 1 && dy > 0 && dy < this.width - 1 && this.grid[dx][dy] === '1') {
            this.grid[dx - directions[i][0]][dy - directions[i][1]] = '0';
            this.grid[dx][dy] = '0';
            this.generateMaze(dx, dy);
        }
    }
};

Maze.prototype.saveMazeToFile = function(filename) {
    let mazeString = '';
    for (let i = 0; i < this.height; i++) {
        mazeString += this.grid[i].join('') + '\n';
    }
    fs.writeFileSync(filename, mazeString);
};

Maze.prototype.removeWalls = function(percentage) {
    let totalWalls = 0;
    for (let i = 1; i < this.height - 1; i++) {
        for (let j = 1; j < this.width - 1; j++) {
            if (this.grid[i][j] === '1') {
                totalWalls++;
            }
        }
    }

    let wallsToRemove = Math.floor(totalWalls * (percentage / 100));

    while (wallsToRemove > 0) {
        let x = Math.floor(Math.random() * (this.height - 2)) + 1;
        let y = Math.floor(Math.random() * (this.width - 2)) + 1;

        if (this.grid[x][y] === '1') {
            this.grid[x][y] = Math.random() < 0.3 ? 'C' : '0';
            wallsToRemove--;
        }
    }
};

let size = parseInt(process.argv[2]); 
let maze = new Maze(size, size);
maze.removeWalls(20);
maze.saveMazeToFile("map.ber");