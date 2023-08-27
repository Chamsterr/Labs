<template>
  <div class="main" ref="z">
    <form class="game">
      <div v-for="(box, boxID) in fields">
        <input v-for="(cell, id) in box" :id="`${boxID}_${id}`" :value="cell" maxlength="1" v-on:focus="focus(boxID, id)"
          v-on:input="change(boxID, id)">
      </div>
    </form>
  </div>
</template>

<script lang="ts">
import { defineComponent } from "vue";
let n: null = null
export default {
  data() {
    return {
      fields: new Array<Array<any>>(
        new Array<any>(5, 3, n, 6, n, n, n, 9, 8), new Array<any>(n, 7, n, 1, 9, 5, n, n, n), new Array<any>(n, n, n, n, n, n, n, 6, n),
        new Array<any>(8, n, n, 4, n, n, 7, n, n), new Array<any>(n, 6, n, 8, n, 3, n, 2, n), new Array<any>(n, n, 3, n, n, 1, n, n, 6),
        new Array<any>(n, 6, n, n, n, n, n, n, n), new Array<any>(n, n, n, 4, 1, 9, n, 8, n), new Array<any>(2, 8, n, n, n, 5, n, 7, 9)
      ),
      cellArray: new Set<number | null>()
    }
  },
  methods: {
    neighboringCellsAndBox(current: any, boxID: number, id: number, direction: number) {
      let neighboringCellsAndBox = new Map<any, any>()
      neighboringCellsAndBox.set(0, [[1, 2], [3, 6]])
      neighboringCellsAndBox.set(1, [[0, 2], [4, 7]])
      neighboringCellsAndBox.set(2, [[0, 1], [5, 8]])
      neighboringCellsAndBox.set(3, [[4, 5], [0, 6]])
      neighboringCellsAndBox.set(4, [[3, 5], [1, 7]])
      neighboringCellsAndBox.set(5, [[3, 4], [2, 8]])
      neighboringCellsAndBox.set(6, [[7, 8], [0, 3]])
      neighboringCellsAndBox.set(7, [[6, 8], [1, 4]])
      neighboringCellsAndBox.set(8, [[6, 7], [2, 5]])

      neighboringCellsAndBox.get(boxID)[direction].forEach((element: number) => {
        this.cellArray.add(this.fields[element][id])
        current?.addEventListener("focusin", () => document.getElementById(`${element}_${id}`)?.classList.add('focused'));
        current?.addEventListener("blur", () => document.getElementById(`${element}_${id}`)?.classList.remove('focused'), true);

        neighboringCellsAndBox.get(id)[direction].forEach((cell_id: number) => {
          let cell = document.getElementById(`${element}_${cell_id}`)
          this.cellArray.add(this.fields[element][cell_id])

          current?.addEventListener("focusin", () => cell?.classList.add('focused'));
          current?.addEventListener("blur", () => cell?.classList.remove('focused'), true);
        });
      });
    },

    focus(boxID: number, id: number) {
      this.cellArray.clear()
      let currentCell = document.getElementById(`${boxID}_${id}`)

      for (let i = 0; i < 9; i++) {
        let cell = document.getElementById(`${boxID}_${i}`)
        this.cellArray.add(this.fields[boxID][i])
        currentCell?.addEventListener("focusin", () => cell?.classList.add('focused'));
        currentCell?.addEventListener("blur", () => cell?.classList.remove('focused'), true);
      }

      this.neighboringCellsAndBox(currentCell, boxID, id, 0)
      this.neighboringCellsAndBox(currentCell, boxID, id, 1)
    },

    change(boxID: number, id: number) {
      let cell = <HTMLInputElement>document.getElementById(`${boxID}_${id}`)
      cell?.classList.remove('wrong');

      if (this.cellArray.has(Number(cell?.value))) {
        this.fields[boxID][id] = Number(cell?.value)
        cell?.classList.add('wrong');
        this.focus(boxID, id)
        console.log(this.cellArray)
      }
      else if (Number(cell?.value) == 0 || cell?.value == null) {
        this.fields[boxID][id] = null
        cell?.classList.remove('quess');
        this.focus(boxID, id)

        let wrongs = document.getElementsByClassName("wrong")
        console.log(wrongs)

        for (let item of wrongs) {
          let idArr = item.getAttribute("id")
          let boxID: number = Number(idArr?.split("_")[0])
          let id: number = Number(idArr?.split("_")[1])

          this.fields[boxID][id] = null
          this.focus(boxID, id)
          this.change(boxID, id)
        }
      }
      else {
        this.fields[boxID][id] = Number(cell?.value)
        cell?.classList.add('quess');
      }
    }
  }
}
</script>

<style>
.quess {
  background-color: #01a595;
}

* {
  margin: 0px;
  padding: 0px;
  color: wheat;
  background-color: #042940;
}

html,
body {
  height: 100%;
}

.game {
  height: 558px;
  width: 558px;
  border: 2px solid wheat;
  display: flex;
  flex-wrap: wrap;
}

.game>div {
  box-sizing: border-box;
  border: 2px solid wheat;
  height: 186px;
  width: 186px;
  display: flex;
  flex-wrap: wrap;
}

.game>div>div,
input {
  text-align: center;
  font-size: 35px;
  box-sizing: border-box;
  border: 1px solid wheat;
  outline: none;
  height: 60.9px;
  width: 60.9px;
  caret-color: transparent;
}

input:focus {
  background-color: #008376;
}

::-webkit-input-placeholder {
  /* WebKit browsers */
  color: #eef996;
}

#app {

  height: 100%;
  display: flex;
  justify-content: center;
  align-items: center;
}

.focused {
  background-color: #005c53;
}

.wrong {
  background-color: #5c0008;
}
</style>