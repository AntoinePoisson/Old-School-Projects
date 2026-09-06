import React, { Component } from 'react';
import Header from './page_body/header';
import Page from './page_body/page';

class App extends Component {
   render() {
      return (
         <div>
            <Header/>
            <Page/>
         </div>
      );
   }
}

export default App;
