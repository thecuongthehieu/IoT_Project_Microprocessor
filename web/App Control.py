#!/usr/bin/env python

import flask

temperature = 37

# Create the application.
APP = flask.Flask(__name__)


@APP.route('/')
def index():
    """ Home 
    """
    return flask.redirect('/<response>')

@APP.route('/update/<temp>')
def update(temp):
    global temperature
    temperature = temp
    return ('', 204)


@APP.route('/<response>')
def hello(response):
    """ Displays the page.
    """
    return flask.render_template('page.html', response=temperature)


if __name__ == '__main__':
    APP.debug=True
    APP.run()