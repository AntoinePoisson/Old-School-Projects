import React, { Component } from "react";
import TextField from "@material-ui/core/TextField";
import { Autocomplete } from "@material-ui/lab";
import TESNUL from "../../src/resources/caca.json";
import IsModale from "./GridList/Modale.jsx";

export default class CustomizedSearch extends Component {

  state = {
    data : {},
    state: false
  }

  handleChangeValue = name => (event) => {
    console.log("OKKKKKK", this.state);
    this.setState({
      data: {},
      state: false

    })
    if (event) {
      var toto = event.target.id;
      var sol = toto.split('-')[4]
      if (!sol || sol === undefined)
        return;
      TESNUL.map((ok, index) => {
        if (index === parseInt(sol)) {
          console.log("OOOOOOOOOKKKKKKKKKKKKKKKKK", index, sol);
          this.setState({
            data: ok,
            state: true
          })
        }
        return (true);
      })
      console.log("ADZDA", event.target.id, sol);
    }
    // setLocalState({ ...localState, [name]: event.target.value });
    // setErrors({ ...errors, [`error_${name}`]: false })
    // setChange(true);
};

  render() {
    return (
      <div>
      <Autocomplete
        id="combo-box-demo"
        options={TESNUL}
        getOptionLabel={option => option.title}
        style={{
          width: 300,
          height: 50,
          backgroundColor: "#rgb(176, 176, 176)"
        }}
        onChange={this.handleChangeValue('zeaz')}
        renderInput={(params, index) =>
          <TextField
            {...params}
            id={index}
            label="Search Pictures"
            variant="outlined"
            fullWidth
          />}
      />
      <IsModale isOpened={this.state} handleClose={() => this.setState({data: {}, state: false}) } />
      </div>
    );
  }
}
