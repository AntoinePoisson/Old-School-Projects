import React from "react";
import { BrowserRouter as Router, Switch, Route } from "react-router-dom";
import Connection from "./views/connection/Connection"
import Dashboard from "./views/dashboard/Dashboard"

import './Routes.css';

function Routes() {
  return (
    <Router className="router">
      <Switch>
        <Route exact path="/login" component={Connection} />
        <Route exact path="/dashboard" component={Dashboard} />
        <Route exact path="*" component={Connection} />
      </Switch>
    </Router>
  );
}

export default Routes;
