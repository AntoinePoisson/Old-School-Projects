import React, { Component } from 'react';
import MyLogin from './Login/mylogin'
import MyAdmin from './Board/Admin'

class App extends Component {
   state = {
      username: '',
      password: '',
      logSuccess: false,
   }

   registering = (username, password, logSuccess) => {
      this.setState({
         username, 
         password,
         logSuccess,
      })
   }

   render() {
      return (
         <div>
            { this.state.logSuccess === false ? <MyLogin registering={this.registering}/> :
               <MyAdmin/>
            }
         </div>
      );
   }
}

export default App;
