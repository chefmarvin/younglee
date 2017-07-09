/**
 * @fileOverview gulp configuration file
 * @name gulpfile.js<app-gov-tv>
 * @author Young Lee <youngleemails@gmail.com>
 * @license MIT
 */
'use strict';

var path = require('path');
var gulp = require('gulp');
var debug = require('gulp-debug');

gulp.task('copy', function () {
    return gulp.src(path.join(__dirname, 'info/*.md')).pipe(gulp.dest(path.join(__dirname, '~/.younglee/'))).pipe(debug({ title: 'copy' }));
});

gulp.task('default', ['copy']);
